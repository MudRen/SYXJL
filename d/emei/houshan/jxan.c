inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�����Ǿ����֣������ʦ̫���޵ĵط�������˼������Ǿ��޵ĺõ�
������һƬ�����У�¶��һ��С�ţ���ȥ�Ϳ�����һ���ɷ���ǵ���ʦ̫��
�����Ƕ����ɵ�����----���ʦ̫���Ա���һ���������Ĺ��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shandao3",
]));            

        set("objects", ([
            __DIR__"npc/miejue" : 1, 
            __DIR__"npc/fblin" : 1,
            ]));

	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",110);
	set("coor/x",-20);
	set("coor/y",130);
	set("coor/z",110);
	setup();
	replace_program(ROOM);
}
