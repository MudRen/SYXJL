// Room: /city/nandajie1.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
        set("short", "�ϴ��");
        set("long", @LONG
    �ϴ�����ǳ���ķ����ضΣ�һ�����ϣ�һ�ɵƺ���̣���Ϊ���֡�Ц����
���������������������һƬ��������Ķ��䣬�㲻����Գ��������ʹ�ͣ������
һ����������һ�����ֵĹ㳡��������һ�ҵ��̣�ǽ��д��һ�����ġ������֣���
ϸ��������������ѹ�͵��ּۻ��۵���������������һƬ�����������š�һ��һʮ��
����Ǯ����ԭ�����Ƿ�Բǧ��֮������һ�Ҷĳ���
LONG
        );
        set("outdoors", "����");

        set("exits", ([
                "east" : __DIR__"dangpu",
                "south" : __DIR__"nandajie2",
                "west" : __DIR__"duchang",
                "north" : __DIR__"guangchang",
        ])); 
        set("objects", ([
                __DIR__"npc/zhucong" : 1,
                "/d/city2/npc/flowerg" : 1,
        ]));
        set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	set("coor/x",0);
	set("coor/y",-10);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}

