import re
from typing import Set, List, Generator
from collections import Counter
import string
from pathlib import Path

class TextPreprocessor:
    def __init__(self, stop_words: Set[str]):
        """
        Initialize the text preprocessor with a set of stop words.
        
        Args:
            stop_words (Set[str]): Set of stop words to be removed from the text
        """
        self.stop_words = stop_words
        self.unique_tokens = Counter()
        
    def clean_text(self, text: str) -> List[str]:
        """
        Clean and tokenize a single line of text.
        
        Args:
            text (str): Input text string
            
        Returns:
            List[str]: List of cleaned and tokenized words
        """
        # Convert to lowercase
        text = text.lower()
        
        # Remove punctuation
        text = text.translate(str.maketrans("", "", string.punctuation))
        
        # Tokenize
        tokens = text.split()
        
        # Remove stop words
        tokens = [token for token in tokens if token not in self.stop_words]
        
        return tokens

    def process_file(self, file_path: str, batch_size: int = 1000) -> Generator[List[str], None, None]:
        """
        Process the input file in batches to handle large files efficiently.
        
        Args:
            file_path (str): Path to the input text file
            batch_size (int): Number of lines to process in each batch
            
        Yields:
            Generator[List[str], None, None]: Generator of processed token lists
        """
        try:
            with open(file_path, 'r', encoding='utf-8') as file:
                batch = []
                for line in file:
                    if line.strip():  # Skip empty lines
                        tokens = self.clean_text(line.strip())
                        self.unique_tokens.update(tokens)
                        batch.append(tokens)
                        
                        if len(batch) >= batch_size:
                            yield batch
                            batch = []
                            
                if batch:  # Yield remaining batch
                    yield batch
                    
        except FileNotFoundError:
            raise FileNotFoundError(f"Input file not found: {file_path}")
        except Exception as e:
            raise Exception(f"Error processing file: {str(e)}")

    def get_unique_token_count(self) -> int:
        """
        Get the total number of unique tokens across all processed text.
        
        Returns:
            int: Number of unique tokens
        """
        return len(self.unique_tokens)

def main(input_file: str, stop_words: Set[str]) -> None:
    """
    Main function to process the text file and output results.
    
    Args:
        input_file (str): Path to input file
        stop_words (Set[str]): Set of stop words
    """
    processor = TextPreprocessor(stop_words)
    
    try:
        # Process file in batches
        for batch in processor.process_file(input_file):
            # Process each batch (can be extended for additional processing)
            pass
            
        # Output results
        print(f"Total number of unique tokens: {processor.get_unique_token_count()}")
        
    except Exception as e:
        print(f"Error: {str(e)}")

if __name__ == "__main__":
    # Example usage
    input_file = "reviews.txt"  # Replace with your input file path
    
    # Example stop words (replace with your predefined list)
    stop_words = {'is', 'the', 'and', 'to', 'a', 'in', 'that', 'of', 'for', 'it'}
    
    main(input_file, stop_words)