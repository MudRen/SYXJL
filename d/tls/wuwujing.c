inherit ROOM;

void create()
{
        set("short", "���޾�");
        set("long",@LONG
һƬˮ�ؾ�����ǰ��һ������ľ�ź�����ϣ����䵹Ӱǡ��һԲ��ӳ
�ſ����ˮ�棬ʹ�����������������·���ᵽ������֮Դ������֮����
���С�
LONG
        );
	set("outdoors","tianlongsi");
        set("exits", ([
		"southdown": __DIR__"yaotai",
		"west" : __DIR__"doumugong",
	  ]));
	set("objects",([
		__DIR__"npc/xing-yu" : 1,
	]));

        set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",30);
	set("coor/x",-40);
	set("coor/y",-110);
	set("coor/z",30);
	setup();
        replace_program(ROOM);
}
