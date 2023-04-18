int size = 256 << 20; // 256MB  
char *p = (char*)malloc(size) + size;  
__asm__("movl %0, %%esp\n" :: "r"(p));
