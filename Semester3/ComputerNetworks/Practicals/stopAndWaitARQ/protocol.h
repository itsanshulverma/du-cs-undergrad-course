#include <iostream>
#include <string>
#define MAX_PKT_SIZE 4
using namespace std;

typedef enum { dat, ack, nak } frameKind;
typedef enum { wait, frameArrival } eventType;

typedef struct
{
  string data;
} packet;

typedef struct
{
  packet *info;
  frameKind kind;
  int seq;
  int ack;
} frame;

class Protocol
{
public:
  int sentSeq;
  int receivedSeq;

  packet dataPkt;
  frame senderFrame, receiverFrame;

  Protocol()
  {
    sentSeq = receivedSeq = -1;
  }

  int waitForEvent(eventType e)
  {
    return e == frameArrival;
  }

  string showFrameKind(frameKind k)
  {
    switch (k)
    {
    case dat:
      return "Data";
      break;
    case ack:
      return "ACK";
      break;
    case nak:
      return "NAK";
      break;
    }
    return "";
  }

  // SENDER: Network -> Data Link Interface
  void fromNetworkLayer(packet &i)
  {
    cout << "\nEncapsulating Packet: '" << i.data << "'...";
    senderFrame.seq = ++sentSeq;
    senderFrame.kind = dat;
    senderFrame.info = &i;
  }

  // SENDER: Data Link -> Physical Interface
  void toPhysicalLayer(frame &f)
  {
    if (f.kind == dat)
      cout << "\nSending DataFrame [" << showFrameKind(f.kind) << ": " << f.seq << "] to Physical Layer...";
    else
      cout << "\nSending ControlFrame [" << showFrameKind(f.kind) << ": " << f.ack << "] to Physical Layer...";
  }

  // RECEIVER: Physical -> Data Link Interface
  void fromPhysicalLayer(frame &f)
  {
    cout << "\nReceived DataFrame [" << showFrameKind(f.kind) << ": " << f.seq << "] from Physical Layer...",
    cout << "\nValidating Sequence Number... ";
    if (receivedSeq != f.seq)
      cout << "\nDecapsulating Frame...";
    else
    {
      cout << "\nDuplicate Frame Encountered... Discarding Frame...";
    }
  }

  // RECEIVER: Data Link -> Network Interface
  void toNetworkLayer(packet &p)
  {
    cout << "\nSending Packet ['" << p.data << "'] to Network Layer...";
    receivedSeq = senderFrame.seq;
    receiverFrame.seq = 0;
    receiverFrame.kind = ack;
    receiverFrame.ack = senderFrame.seq + 1;
  }
};