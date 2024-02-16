class Solution:

    def arePalindromes(self, l: list[str]):
        for string in l:
            if string != string[::-1]: return False

        return True

    def getSublists(self, sublist: list, sublists: list):
        sublists.append(sublist)
        target = sublist[-1]
        if len(target) == 1: return sublists

        for i in range(1, len(target)):
            new_parts = [target[:i], target[i:]]
            new_sublist = sublist[:-1]
            new_sublist.extend(new_parts)
            self.getSublists(new_sublist, sublists)

        return sublists


    def partition(self, s: str) -> List[List[str]]:
        sublists = self.getSublists([s], [])

        results = []
        for sublist in sublists:
            if self.arePalindromes(sublist):
                results.append(sublist)
        
        return results


        