// damen.c
//written by dewey 

inherit ROOM; 

void create() 
{
	set("short", "��ݴ���"); 
	set("long",@LONG
����һ�����ƺ�����ݣ����Ŷ����ţ��ſڶ׾�������
���͵�ʯʨ�ӣ�����ﴫ��һ�����������������˵������
�Ѿ����ϰ������ʷ�ˡ��κ���ֻҪ��Ǯ�����������ѧ��һ
Щ��ǳ�Ĺ���
LONG);
       
        set("exits",([
        "east" : "/home/editor/workroom",
        ])); 
	
        setup(); 
	
} 
