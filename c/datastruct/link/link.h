#ifndef link_h_2022_04_02
#define link_h_2022_04_02

typedef struct Link 
{
    char elem; 
    struct Link * next;
}link;

typedef struct line
{
    int           data;
    struct line * next, * prior;
}line;

typedef enum bool
{
    False = 0,
    True = 1
}bool;

#ifdef __cplusplus
extern "C" {
#endif

bool haveRing(link *H);
bool isSingleLinkCross(link * L1, link * L2);

#ifdef __cplusplus
}
#endif

#endif