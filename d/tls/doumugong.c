inherit ROOM;

void create()
{
        set("short", "��ĸ��");
        set("long",@LONG
���Ǹ����������Ϣ�ĵط�������Χ����һ��̴ľ�����Ρ���������
������������Ϣ�������ǿ��Կ���ɮ������Ϣ�����ĸ󣬱��洫��������
������������Ҫ�������µĺ���ص��ˡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"qingxinge",
                "east" : __DIR__"wuwujing",
                "north" : __DIR__"yuhuayuan",
                "west" : __DIR__"sanwugong",
        ]));
        set("objects",([
                __DIR__"npc/guest" : 3,
        ]));
        set("coor/x",-50);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-50);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
