inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���Ǻ�ľ�µ������������£�ɽ�����ɸ����Ʋ�һ�أ�����������
���ߣ����Խ���Ʈ�����¡�
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southdown" : __DIR__"guanpu",
]));
        set("objects", ([
                __DIR__"npc/tufei1" : 1,
                __DIR__"npc/tufei2" : 1,
        ]));

        setup();
}
