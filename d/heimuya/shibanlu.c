inherit ROOM;

void create()
{
        set("short", "ʯ��·");
        set("long", @LONG
������һ������ʯ��������ɵ�ʯ��·��ÿ��ʯ�嶼��ʮ�߼�������
���ޱȣ���·�����������½̵���ţ��ɴ�һֱ���ӵ�һ����ΰ��¥��
֮ǰ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pailou",
  "east" : __DIR__"qiandian",
]));
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/shizhe" : 2,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
