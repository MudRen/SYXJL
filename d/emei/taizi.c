inherit ROOM;

void create()
{
	set("short", "̫��ƺ");
	set("long", @LONG
������ǧ�������ߵ�̫��ƺ���Ƕ��������׵ĵ����������ĳ�����
����Ƭ�����Ĳ�ƺ��ɢ���ż������׵Ļ�û�г��ҵ�СŮ����				
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southdown" : __DIR__"xiaodao",
]));
	set("objects",([
           __DIR__"npc/girl2" : 3, 
           __DIR__"npc/nigu1" : 1,
           __DIR__"npc/zhou" : 1,
             ]));    

	set("coor/x",-80);
	set("coor/y",50);
	set("coor/z",120);
	set("coor/x",-80);
	set("coor/y",50);
	set("coor/z",120);
	set("coor/x",-80);
	set("coor/y",50);
	set("coor/z",120);
	setup();
	replace_program(ROOM);
}
