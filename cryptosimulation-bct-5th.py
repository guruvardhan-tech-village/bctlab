# Simple Cryptocurrency Simulation for Multiple Users

class Cryptocurrency:
    def __init__(self):
        # Dictionary to store user balances
        self.balances = {}

    def create_user(self, username):
        if username in self.balances:
            print(f"User '{username}' already exists.")
        else:
            self.balances[username] = 100  # Give initial coins
            print(f"User '{username}' created with 100 coins.")

    def transfer(self, sender, receiver, amount):
        # Check if both users exist
        if sender not in self.balances or receiver not in self.balances:
            print("Sender or receiver does not exist.")
            return

        # Check if sender has enough coins
        if self.balances[sender] < amount:
            print(f"'{sender}' does not have enough coins.")
            return

        # Transfer coins
        self.balances[sender] -= amount
        self.balances[receiver] += amount
        print(f"Transferred {amount} coins from {sender} to {receiver}.")

    def show_balances(self):
        print("\n--- User Balances ---")
        for user, balance in self.balances.items():
            print(f"{user}: {balance} coins")
        print("----------------------")


# ------- Main Program -------
if __name__ == "__main__":
    crypto = Cryptocurrency()

    # Creating multiple users
    crypto.create_user("Alice")
    crypto.create_user("Bob")
    crypto.create_user("Charlie")

    # Transactions
    crypto.transfer("Alice", "Bob", 30)
    crypto.transfer("Bob", "Charlie", 10)
    crypto.transfer("Charlie", "Alice", 50)

    # Printing all balances
    crypto.show_balances()
