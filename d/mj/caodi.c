// Room: caodi.c

inherit ROOM;

void create()
{
        set("short", "�ݵ�");
        set("long", @LONG
����һƬ�����де���ݵأ������������Ƶ���ɽ���ݴ��м���
��һЩ��ɫ��Ұ���������������һ�㡣ʱ������Щ��С�����������
Զ���м�ͷСţ���������еسԲݡ�������ţСͯ����һ��׷����Ϸ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"shanpo2",
  "east" : __DIR__"caodi1",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        set("coor/x",-90);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",100);
	set("coor/z",0);
	set("coor/x",-90);
	set("coor/y",100);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

