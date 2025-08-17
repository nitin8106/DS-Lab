#inclde<stdio.h>
struct Student {
	int roll_no;
	char name[50];
	int marks[5];
	int total;
};
int main(){
	struct Student s;
	s.total=0;
	int i=0;
	printf("Enter roll number: ");
	scanf("%d",&s.roll_no);
	
	printf("Enter name: ");
	scanf("%[^\n]",s.name);
	
	
}
