inherit ROOM;

void create()
{
        set("short", "��ʯ���");
        set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��������ͨ�������ɽ--��ɽ��
������ɽ�������Ѵ�����ˡ�
LONG
        );
        set("outdoors", "dali");

        set("exits", ([
                "east" : "/d/wudang/wdroad1",
                "southup" : __DIR__"cangshan",
                "north" :"/d/shashou/enterance",
                
        ]));

        set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
