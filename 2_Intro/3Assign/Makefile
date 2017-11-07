
all :
	gcc -o Bubble.out main.c bubble.c general.c -D BUBBLE
	gcc -o Selection.out main.c selection.c general.c -D SELECTION
	gcc -o Insertion.out main.c insertion.c general.c -D INSERTION
	gcc -o Merge.out main.c merge.c general.c -D MERGE
	gcc -o Quick.out main.c quick.c general.c -D QUICK
	gcc -o Random-Quick.out main.c random-quick.c general.c -D RANDOM-QUICK
	gcc -o Compare.out main.c bubble.c selection.c insertion.c merge.c quick.c random-quick.c general.c -D COMPARE
bubble:
	gcc -o Bubble.out main.c bubble.c general.c -D BUBBLE

selection:
	gcc -o Selection.out main.c selection.c general.c -D SELECTION

insertion:
	gcc -o Insertion.out main.c insertion.c general.c -D INSERTION

merge:
	gcc -o Merge.out main.c merge.c general.c -D MERGE

quick:
	gcc -o Quick.out main.c quick.c general.c -D QUICK

random-quick:
	gcc -o Random-Quick.out main.c random-quick.c general.c -D RANDOM-QUICK

clean	:
	rm -rf *.out

compare:
	gcc -o Compare.out main.c bubble.c selection.c insertion.c merge.c quick.c random-quick.c general.c -D COMPARE

#run:
	#gcc -o Compare.out main.c bubble.c selection.c insertion.c merge.c quick.c random-quick.c general.c -D
	#./Compare.out
