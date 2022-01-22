class Account:

    __accounts = []

    def __init__(self):
        pass

    def add(self, name):
        self.__accounts.append(name)

    def modify(self, name, new_name):
        try:
            i = self.__accounts.index(name)
            self.__accounts[i] = new_name
        except ValueError as e:
            print('Account not found.')

    def delete(self, name):
        self.__accounts.remove(name)

    def search(self, name):
        if name in self.__accounts:
            print('Account found!')
        else:
            print('Account not found!')

acc = Account()
print('Adding account \'Ram\'...')
acc.add('Ram')
print('Adding account \'Shyam\'...')
acc.add('Shyam')
print('Adding account \'Anubhav\'...')
acc.add('Anubhav')
print('Adding account \'Aman\'...')
acc.add('Aman')
print('Searching account \'Ram\'...')
acc.search('Ram')
print('Modifying account \'Ram\' to \'Ramanujan\'...')
acc.modify('Ram', 'Ramanujan')
print('Searching account \'Ram\'...')
acc.search('Ram')
print('Deleting account \'Shyam\'...')
acc.delete('Shyam')
