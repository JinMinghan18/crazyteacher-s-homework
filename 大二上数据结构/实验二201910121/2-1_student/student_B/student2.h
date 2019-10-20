//student2.h
class Student {
public:
	Student();
	Student(const char * n);
	Student(const Student & o);
	void operator=(const Student& o);
	~Student( );
	char  *GetName();
	void  ChangeName(const char *n);
private:
	char *name;
};
