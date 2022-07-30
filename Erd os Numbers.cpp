/*input:1

4 3
Smith, M.N., Martin, G., Erdos, P.: Newtonian forms of prime factors
Erdos, P., Reisig, W.: Stuttering in petri nets
Smith, M.N., Chen, X.: First order derivates in structured programming

Jablonski, T., Hsueh, Z.: Selfstabilizing data structures
Smith, M.N.
Hsueh, Z.
Chen, X.*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <string.h>
#define MIN(a, b) (b) < (a) ? (b) : (a) 
struct author {
int order;
struct author *next;
char fullname[];
};
struct author *
author_find(struct author *authors, const char *fullname)
{
for (struct author *a = authors; a; a = a->next)
if (strcmp(a->fullname, fullname) == 0)
return a;
return NULL;
}
struct author *
author_push(struct author **authors, const char *last, const char *initals)
{
size_t namelen = strlen(last) + 2 + strlen(initals) + 1;
struct author *author = malloc(sizeof(*author) + namelen);
sprintf(author->fullname, "%s, %s", last, initals);
author->order = INT_MAX;
author->next = *authors; 
*authors = author;
return author;
}
void
author_merge(struct author **authors, struct author *paper)
{
int order = INT_MAX;
for (struct author *a = paper; a; a = a->next) {
struct author *original = author_find(*authors, a->fullname);
if (original && original->order < INT_MAX)
order = MIN(order, original->order + 1);
}
while (paper) {
struct author *author = paper;
struct author *original = author_find(*authors, author->fullname);
paper = paper->next;
if (original) {
free(author);
original->order = MIN(original->order, order);
} else { 
author->order = order;
author->next = *authors;
*authors = author;
}
}
}
void
author_free(struct author **authors)
{
while (*authors) {
struct author *dead = *authors;
*authors = (*authors)->next;
free(dead);
}
*authors = NULL;
}
int main(void)
{
struct author *authors = NULL;
author_push(&authors, "Erdös", "P.")->order = 0; 
int num_papers, num_authors;
scanf("%d %d ", &num_papers, &num_authors);
for (int i = 0; i < num_papers; i++) {
struct author *paper = NULL;
bool final = false;
while (!final) {
int c;
if ((c = getchar()) == '&')
final = true;
else
ungetc(c, stdin);
char last[64], initials[8];
scanf(" %63[^, ], %7[^,(], ", last, initials);
if (final)
initials[strlen(initials) - 1] = '\0';
author_push(&paper, last, initials);
}
while (getchar() != '\n');
author_merge(&authors, paper);
} 
for (int i = 0; i < num_authors; i++) {
char line[256];
fgets(line, sizeof(line), stdin);
line[strlen(line) - 1] = '\0';
struct author *author = author_find(authors, line);
if (author && author->order < INT_MAX)
printf("%s %d\n", author->fullname, author->order);
else
printf("%s %s\n", line, "infinity");
}
author_free(&authors);
return 0;
}