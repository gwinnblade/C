#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool is_valid_ip(const char *ip){
	int num = 0, dots = 0;
    const char *p = ip;
    
    if (strlen(ip) > 15) return false;
	
	while (*p){
		if (*p == '.'){
			dots++;
			if(num < 0 || num > 255) return false;
			num = 0;
		} else if (isdigit(*p)){
			num = num * 10 + (*p - '0');
			if (num > 255) return false;
		} else {
			return false;
		}
		p++;
	}
	return (dots == 3 && num >= 0 && num <= 255);
}

int main(){
	char ip[16];
	printf("Input IP-Adress: ");
	if (fgets(ip, sizeof(ip), stdin)) {
		ip[strcspn(ip,"\n")] = '\0';
		
		if (is_valid_ip(ip)){
			printf("IP-Adress Valid");
		}
		else {
			printf("IP-Adress Invalid");
		}
	} else {
		printf("Error: in input");
	}
	return 0;
}
