#developed by Narendra Vardi
#Motivation for developing this file is that I have solved problems in HackerRank for which I got partial output.
#When I download the HackerRank testcase and try to check where I went wrong, The Output file will be so complex that it becomes very tough for me to 
# find the line where i am going wrong, so I wrote this program which gives me the line number where I went wrong.
#save your HackerRank output in hrop.out
#save your output in op.out
#Just run this file, This will give the line number where there is change.
# this will print all the line count for all the lines that mismatch
#**This program has been developed assuming that both files will have same number of lines

hroutput = open('hrop.out')
output = open('op.out') 
count=1;
hroutputlist=[]
outputlist=[]
for line in hroutput:
	hroutputlist.append(line.strip())
for line in output:
	outputlist.append(line.strip())

for i in xrange(0,len(outputlist)):
	if(hroutputlist[i]!=outputlist[i]):
		print count
		count+=1
	else:
		count+=1
