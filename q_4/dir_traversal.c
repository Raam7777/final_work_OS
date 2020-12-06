#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int get_inode (int fd){
    struct stat buf;
    int ret;

    ret = fstat(fd, &buf);
    
    if ( ret <0 ) {
         perror ("fstat");
         return -1;
    }

    return buf.st_ino;
}

static int display_info(const char *fpath, const struct stat *sb, int tflag, struct FTW *ftwbuf) {
    if(tflag != FTW_SL) {
        int fd = open(fpath, O_RDONLY);
        int inode = get_inode(fd);
        printf("%s %d %s\n",
            (tflag == FTW_D) ?   "D"   : (tflag == FTW_DNR) ? "dnr" :
            (tflag == FTW_DP) ?  "dp"  : (tflag == FTW_F) ?   "F" :
            (tflag == FTW_NS) ?  "ns"  : (tflag == FTW_SLN) ? "sln" : "???",
            inode,fpath + ftwbuf->base);
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2){
        printf("./dir_traversal <dir path>\n");
        exit(1);
    }

    int flag = FTW_D;

    int ret = nftw(argv[1], display_info , 20 , flag);

    if (ret == -1){
        perror("nftw");
        exit(1);
    }
    exit(0);
}



//http://fibrevillage.com/scripting/25-get-inode-number-of-a-given-file
//https://pubs.opengroup.org/onlinepubs/9699919799/functions/nftw.html
