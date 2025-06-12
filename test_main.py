import subprocess
import unittest

class TestMain(unittest.TestCase):
    def test_main_output(self):
        result = subprocess.run(['python', 'main.py'], capture_output=True, text=True, check=True)
        self.assertEqual(result.stdout.strip(), '[1, 2, 3, 4, 5]')

if __name__ == '__main__':
    unittest.main()
