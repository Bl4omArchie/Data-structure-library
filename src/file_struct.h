#ifndef FILE_STRUCT_H
#define FILE_STRUCT_H

typedef struct File_s File_t;

struct File_s {
    
};


File_t* File_creer();
void File_enfiler(File_t* f, int v);
int File_defiler(File_t* f);
int File_taille(const File_t* f);
bool File_vide(const File_t* f);
// int File_premier(const File_t* f);
// int File_dernier(const File_t* f);
void File_liberer(File_t* f);


#endif