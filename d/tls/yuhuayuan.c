inherit ROOM;

void create()
{
        set("short", "�껨Ժ");
        set("long",@LONG
�ഫ������潵�������´���ʱ����������껨ʯ��������ʯ��
Ժ�����ɴ˼���Ժ��
LONG
        );
        set("exits", ([
 //               "west" : __DIR__"fanting",
		"south" : __DIR__"doumugong",
                "east" : __DIR__"bingqifang",
                "northdown" : __DIR__"xuanya",  
	]));
	set("objects",([
		__DIR__"npc/gui-xiang" : 1,
	]));

        set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-100);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}


int valid_leave(object me,string dir)
{
        if(dir=="west" && (!me->query("family") 
                || me->query("family")["family_name"]!="������"))
                return notify_fail("·�м�����һ����ʯ����������д�����������µ��ӣ�������롣\n");
        return ::valid_leave(me,dir);
}

