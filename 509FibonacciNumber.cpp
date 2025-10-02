class Solution:
    def fib(self, n: int) -> int:
        tab = [0,1];
        for i in range(2,n+1):
            aux = tab[i-1] + tab[i-2]
            tab.append(aux)
        return tab[n]

        
