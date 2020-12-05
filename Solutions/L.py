def lcs(X, Y): 
	m = len(X) 
	n = len(Y) 

	L = [[None]*(n + 1) for i in range(m + 1)] 

	for i in range(m + 1): 
		for j in range(n + 1): 
			if i == 0 or j == 0 : 
				L[i][j] = 0
			elif X[i-1] == Y[j-1]: 
				L[i][j] = L[i-1][j-1]+1
			else: 
				L[i][j] = max(L[i-1][j], L[i][j-1]) 

	return L[m][n] 



def main():
    inp = input()
    [L,C] = [int(x )for x in inp.split(' ')]
    a =0
    words_database = []
    words = []
    while(a < L):
        inp = input()
        words_database.append(inp)
        a+=1

    inp = int(input())
    d = inp
    a=0
    o = True

    while(a < d):
        inp = input()
        words.append(inp)
        a+=1

    matches = 0
    x = []

    for i in range(len(words_database)):
        for k in range(len(words_database)):
            if( i != k):
                if ( words_database[i].find(words_database[k]) >= 0):
                    o = False

    if( o == True):

        for i in words_database:
            for w in words:
                if ( i.find(w) >= 0 and len(w) == C):
                    matches+=1

        for R in words_database:
            x.append(R)
        x = ''.join(x)

        x = sorted(x)

        for T in words:
            if (lcs(x, sorted(T)) == len(T)):
                matches+=1
        print(matches)

    else:
        print("0")


if __name__ == "__main__":
    main()