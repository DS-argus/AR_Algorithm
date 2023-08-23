class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        Phone = {'2': ['a', 'b', 'c'],
                '3': ['d', 'e', 'f'],
                '4': ['g', 'h', 'i'],
                '5': ['j', 'k', 'l'],
                '6': ['m', 'n', 'o'],
                '7': ['p', 'q', 'r', 's'],
                '8': ['t', 'u', 'v'],
                '9': ['w', 'x', 'y', 'z']}
        
        result = []

        letter = ""

        def dfs(idx, letter):

            if idx == len(digits):
                result.append(letter)
                return

            digit = digits[idx]
            values = Phone[digit]

            for value in values:
                dfs(idx+1, letter+value)
                # letter = letter[:-1]

        dfs(0, letter)

        if result == [""]:
            result = []

        return result


