inherit ROOM;

void create()
{
	set("short", "���䳡");
	set("long", @LONG
�����������µ����䳡����������޴�Ļ�����ʯ���̾͡�
��ǧ��Ĳ�̤��ʹ����Щʯ����ͬ���Ӱ�ƽ���⻬�����䳡�м�
�����Ų��ٲݰС�ʮ����ɮ��������ϰ���ա��������䳡���ġ�
LONG
	);

	set("exits", ([
		"north" : __DIR__"wuchang",
	]));

	set("objects",([
                __DIR__"npc/mu-ren" : 2 
          ]));

	set("outdoors", "tianlongsi");

	set("coor/x",-80);
	set("coor/y",-140);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-140);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-140);
	set("coor/z",20);
	set("coor/x",-80);
	set("coor/y",-140);
	set("coor/z",20);
	setup();
	replace_program(ROOM);
}


