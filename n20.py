def isValid(self, s: str) -> bool:
        sp = []
        for i in range(0,len(s)):
            if s[i] == '(' or s[i] == '[' or s[i] == '{':
                sp.append(s[i])
            else: 
                if s[i] == '(':
                    if len(sp) > 0 and sp[-1] == '）':
                        sp.pop()
                    else:
                        return False 
                if s[i] == ']':
                    if len(sp) > 0 and sp[-1] == '[':
                        sp.pop()
                    else:
                        return False
                if s[i] == '}':
                    if len(sp) > 0 and sp[-1] == '{':
                        sp.pop()
                    else:
                        return False 
        if len(sp) == 0:
            return True
        else:
            return False