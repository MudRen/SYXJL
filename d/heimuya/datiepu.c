inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
����һ�Ҽ�ª�Ĵ����̣����İ���һ����¯��¯��������յ�һƬͨ
�죬��һ�߽�ȥ�͸е�������ȡ�ǽ�Ƕ��������깤��δ�깤��������
���ߵ��һλ������ͷ�󺹻�����������ר����־���ڴ�����
LONG
        );
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/tie" : 1,
]));
       set("no_sleep_room", "1");
        set("no_fight", "1");
        set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"pailou",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
