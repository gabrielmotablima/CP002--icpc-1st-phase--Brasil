def main():
	saque = 'e'
	gl = 0
	pl = 0
	gr = 0
	pr = 0
	saque = 'l'
	n = str(input())
	for j in range(len(n)):
		if(n[j] == 'S'):
			if(saque == 'l'):
				pl += 1
			else:
				pr += 1
		elif(n[j] == 'R'):
			if(saque == 'l'):
				pr += 1
				saque = 'r'
			else:
				pl += 1
				saque = 'l'
		elif(n[j] == 'Q'):
			if((gl != 2) and (gr != 2)):
				if(saque == 'l'):
					print(f'{gl} ({pl}*) - {gr} ({pr})')	
				else:
					print(f'{gl} ({pl}) - {gr} ({pr}*)')
			else:
				if(gl == 2):
					print(f'{gl} (winner) - {gr}')	
				elif(gr == 2):
					print(f'{gl} - {gr} (winner)')
		
		if(((pl >= 5) and (pr <= pl-2)) or (pl == 10)):
			pl = 0
			pr = 0
			gl += 1
			saque = 'l'
		elif(((pr >= 5) and (pl <= pr-2)) or (pr == 10)):
			pl = 0
			pr = 0
			gr += 1
			saque = 'r'
		
if __name__ == "__main__":
	main()
