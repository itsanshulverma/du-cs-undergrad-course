#include <iostream>
#include "protocol.h"

class StopAndWaitARQ : public Protocol
{
public:
  string msg;
  eventType event;

  bool flag, start;
  int timeout_t, count, len, partSize;

  StopAndWaitARQ(string s, int t)
  {
    msg = s;
    timeout_t = t;
    partSize = 1e6;
    flag = false;
    start = false;
    count = 0;
  }

  void sender();
  void receiver();
};

void StopAndWaitARQ::sender()
{
  if (!start)
  {
    partSize = msg.length() % MAX_PKT_SIZE == 0
              ? msg.length() / MAX_PKT_SIZE
              : msg.length() / MAX_PKT_SIZE + 1;
    cout << "\nDividing data into groups of " << MAX_PKT_SIZE << " bits each.";
    start = !start;
  }

  cout << "\n\nSENDER\n----------";
  if (count > 0)
  {
    if (count % timeout_t == 0)
    {
      cout << "\nERR: TIMEOUT!";
      flag = true;
    }
    else
    {
      cout << "\nReceived ControlFrame ["<< showFrameKind(receiverFrame.kind) << ": " << receiverFrame.ack << "]...";
      if (flag)
      {
        count--;
        flag = !flag;
      }
    }
    if (receiverFrame.kind == nak || flag)
    {
      cout << "\nResending Previous Frame...";
      count--;
      flag = true;
    }
  }

  if (count == partSize)
  {
    cout << "\n\nData ['" << msg << "'] Sent Successfully.";
    exit(0);
  }

  while (count < partSize)
  {
    while (event != wait)
    {
      if (!flag)
      {
        dataPkt.data = "";
        cout << "\nEncapsulating [Data: " << count + 1 << "] into a Packet...";
        for (int i = 0; i < MAX_PKT_SIZE; i++)
          dataPkt.data += msg[i + count * MAX_PKT_SIZE];
        cout << "\nPassing Packet to Data Link Layer...";
        event = frameArrival;
      }
      if (waitForEvent(event))
      {
        if (!flag)
          fromNetworkLayer(dataPkt);
        toPhysicalLayer(senderFrame);
        event = wait;
      }
      receiver();
    }
  }
}

void StopAndWaitARQ::receiver()
{
  cout << "\n\nRECEIVER\n----------";
  if (event == wait)
  {
    fromPhysicalLayer(senderFrame);
    if (!flag)
    {
      toNetworkLayer(dataPkt);
      count++;
    }
    else
      count += 2;
    toPhysicalLayer(receiverFrame);
    event = frameArrival;
    sender();
  }
}

int main()
{
  string temp;
  cout << "\nEnter Data: ";
  getline(cin, temp);

  int temp2;
  cout << "Simulate noise at (>=2): ";
  cin >> temp2;

  StopAndWaitARQ *obj = new StopAndWaitARQ(temp, temp2);
  obj->sender();
  delete obj;

  cout << endl;
  return 0;
}