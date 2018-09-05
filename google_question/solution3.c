#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char * solution3(char * s, int K){
	// find the length of string
	int length = 0;
	int index = 0;
	while(s[index] != '\0'){
		if(s[index] != '-'){
			length++;
		}
		index++;
	}
	int flag = (K - (length % K)) % K;
	length += length/K - ((length % K == 0) ? 1 : 0);
	char * result = (char *) malloc(sizeof(char) * (length + 1));
	result[length] = '\0';
	int i;
	int reader = 0;
	for (i = 0; i < length; i++){
		if(flag == K){
			result[i] = '-';
			flag = 0;
		}else{
			while(s[reader] == '-'){
				reader++;
			}
			result[i] = toupper(s[reader]);
			reader++;
			flag++;
		}
	}
	return result;
}

int main(){
	char * test1 = solution3("2-4A0r7-4k", 4);
	printf("%s",test1);
	printf("%s","\n");
	free(test1);

	char * test2 = solution3("-a", 1);
	printf("%s",test2);
	printf("%s","\n");
	free(test2);

	char * test3 = solution3("2-4A0r7-4k", 3);
	printf("%s",test3);
	printf("%s","\n");
	free(test3);

	char * test4 = solution3("r", 4);
	printf("%s",test4);
	printf("%s","\n");
	free(test3);

	char * test5 = solution3("r", 1);
	printf("%s",test5);
	printf("%s","\n");
	free(test3);
	// printf("%s",solution3("2-4A0r7-4k", 4));
	// printf("%s",solution3("r", 4));
	// printf("%s",solution3("r", 1));
}


