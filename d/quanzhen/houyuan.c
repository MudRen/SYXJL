//houyuan.c ��Ժ

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ǻ�Ժ��������ͯ��æµ��������ȥ,Ժ�������ż��ù���,Ժ������һ��
ˮ������ȫ���������ˮ����Ҫ��Դ�������ǵ����������һ��С·ͨ���ɽ��
������ʳ�ã������ǲؾ���
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaolu1",
		"south" : __DIR__"disandian",
              "west" : __DIR__"shitang",
             "east" : __DIR__"cangjingge",
	]));
	
	set("outdoors", "quanzhen");
	
	set("coor/x",-90);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",280);
	set("coor/z",190);
	set("coor/x",-90);
	set("coor/y",280);
	set("coor/z",190);
	setup();
	replace_program(ROOM);
}
