inherit ROOM;

void create()
{
        set("short", "���ָ�");
        set("long",@LONG
����������������ǰ�����㻹Ըʱ��Ϣ�ĵط�������̴��¯�����
������һӦ��ȫ���徲֮����Ȼ͸��һ˿����֮��
LONG
        );
        set("exits", ([
		"north": __DIR__"xianghemen",    			
	        "east" : __DIR__"huangtianmen",
	]));
	set("objects",([
                __DIR__"npc/xiaoshami" : 2,
        ]));
        set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",10);
	set("coor/x",-10);
	set("coor/y",-100);
	set("coor/z",10);
	setup();
        replace_program(ROOM);
}