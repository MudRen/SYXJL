// Room: /d/quanzhou/yucun.c
inherit ROOM;
void create()
{
    set("short", "С���");
    set("long", @LONG
һ����ľ����ǳ�����㼸ʮ��Զ�ĺ�̲�ϣ���ˮ������Ĵ��ź�����
��ֻ��Ÿ����������Χ���㼫ĿԶ����������ȴ������һ���洬��
LONG
    );
    set("objects", ([ /* sizeof() == 1 */
	  "/d/npc/salt_seller" : 1,
]));
    set("no_clean_up", 0);
    set("exits", ([ /* sizeof() == 1 */
  	"north" : __DIR__"haigang",
]));
    set("outdoors", "quanzhou");
    setup();
    replace_program(ROOM);
}
