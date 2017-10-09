#include <stdio.h>
#include <string.h>

char num[10][5] = {
    "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};

char wei[5][5] = {
    "Shi", "Bai", "Qian", "Wan", "Yi"
};

int main() {

    char str[15];
    gets(str);
    int len = (int)strlen(str);

    int left = 0, right = len - 1; 
    int zeroFlag = 0, printFlag = 0;
    if(str[0] == '-'){
        printf("Fu");
        left++;
    }

    // left?right?????
    while(left + 3 < right)
        right -= 4;

    while(left < len){
        zeroFlag = 0; // ??????“ling“
        printFlag = 0; 
        while (left <= right) {
            if(left > 0 && str[left] == '0'){
                zeroFlag = 1;
            } else {
                if(zeroFlag){
                    printf(" ling");
                    zeroFlag = 0;
                }
                if(left > 0) printf(" ");
                printf("%s", num[str[left] - '0']);
                printFlag = 1;
                // ????,????????? "Shi" "Bai" "Qian"
                if(left != right)
                    printf(" %s", wei[right - left - 1]);
            }
            left++;
        }
        // ???????? “Wan“,“Yi”
        if(printFlag && right != len - 1)
            printf(" %s", wei[(len - 1 - right) / 4 + 2]);
        right += 4;
    }

    return 0;
}
