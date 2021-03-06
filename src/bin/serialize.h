#ifndef SERIALIZE_H_
# define SERIALIZE_H_

// structure of a property's content
typedef struct  _Elegance_Property Elegance_Property;
struct		_Elegance_Property
{
    const char	*name;
    const char	*data;
};

// structure of a page's content
typedef struct  _Elegance_Content Elegance_Content;
struct		_Elegance_Content
{
    char		*name; // name of the content
    Elegance_Tool	tool; // associated tool structure
    Evas_Object		*obj; // associated Evas object
    Evas_Object		*lay; // content's layout
    Eina_List		*child; // list of content's childs
    int			col; // for insertion into table
    int			row; // for insertion into table
    Eina_Hash		*prop; // object's properties
};

// structure of a project's page
typedef struct  _Elegance_Page Elegance_Page;
struct		_Elegance_Page
{
    char		*name; // name of the page
    Eina_Bool		hide_contents; // hide or show contents in palette
    Eina_List		*contents; // contents' list
};

// structure of a project
typedef struct  _Elegance_Project Elegance_Project;
struct		_Elegance_Project
{
    char		*name; // name of the project
    Eina_List		*pages; // pages' list
};

extern Elegance_Project *actual_project; // actual opened project
extern Elegance_Page *actual_page; // actual select page
extern Elegance_Content *actual_content; // actual select content

void serialize_init(void);
void serialize_print(void);
void serialize_project(char *file);
void hash_table_data_free_cb(void *data);

#endif
