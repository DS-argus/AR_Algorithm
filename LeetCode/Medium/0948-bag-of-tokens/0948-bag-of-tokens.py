class Solution:
    def faceUP(self, tokens, power, score):
        if power >= min(tokens):
            power -= min(tokens)
            tokens.remove(min(tokens))
            score += 1

        return tokens, power, score

    def faceDOWN(self, tokens, power, score):
        if score >= 1:
            power += max(tokens)
            tokens.remove(max(tokens))
            score -= 1
        
        return tokens, power, score

    def bagOfTokensScore(self, tokens: List[int], power: int) -> int:
        if tokens == []: return 0

        score = 0

        while tokens:
            flag = 0
            prev_score = score
            if power >= min(tokens):
                prev_tokens, prev_power, prev_score = tokens, power, score
                tokens, power, score = self.faceUP(tokens, power, score)
                if (prev_tokens == tokens) and (prev_power == power) and (prev_score == score):
                    flag += 1 
            else:
                prev_tokens, prev_power, prev_score = tokens, power, score
                tokens, power, score = self.faceDOWN(tokens, power, score)
                if (prev_tokens == tokens) and (prev_power == power) and (prev_score == score):
                    flag += 1 
            
            if flag == 1 or tokens == []:
                break
        
        return max(score, prev_score)