inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
һ�������Ĺ������������Զ���ǽ��ÿ�������ɣ�ǽ�϶�����һ֧����
�εľ���
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"qianqiudian",
  "south" : __DIR__"chengdedian",
  "west" : __DIR__"qinglongtang",
]));
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhe" : 2,
]));

        setup();
        replace_program(ROOM);
}
