import hashlib
import time

# Define a Block class
class Block:
    def __init__(self, index, timestamp, data, previous_hash):
        self.index = index
        self.timestamp = timestamp
        self.data = data
        self.previous_hash = previous_hash
        self.hash = self.calculate_hash()

    def calculate_hash(self):
        # Combine block fields and compute SHA-256 hash
        text = str(self.index) + str(self.timestamp) + str(self.data) + str(self.previous_hash)
        return hashlib.sha256(text.encode()).hexdigest()


# Define a Blockchain class
class Blockchain:
    def __init__(self):
        # Start chain with the Genesis block
        self.chain = [self.create_genesis_block()]

    def create_genesis_block(self):
        # First block (no previous hash)
        return Block(0, time.ctime(), "Genesis Block", "0")

    def get_latest_block(self):
        return self.chain[-1]

    def add_block(self, new_data):
        prev_block = self.get_latest_block()
        # Index = current length of chain
        new_block = Block(len(self.chain), time.ctime(), new_data, prev_block.hash)
        self.chain.append(new_block)

    def print_chain(self):
        for block in self.chain:
            print("-" * 50)
            print("Block Index :", block.index)
            print("Timestamp  :", block.timestamp)
            print("Data       :", block.data)
            print("Prev Hash  :", block.previous_hash)
            print("Hash       :", block.hash)


# --- Main Program (Demo) ---
if __name__ == "__main__":
    # Create blockchain
    my_chain = Blockchain()

    # Add some blocks
    my_chain.add_block("Block 1: Sent 10 coins to Alice")
    my_chain.add_block("Block 2: Sent 5 coins to Bob")
    my_chain.add_block("Block 3: Received 20 coins from Charlie")

    # Print all blocks
    my_chain.print_chain()
