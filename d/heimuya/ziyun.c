inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�˴��澰����һ��������������ת����������¶���Ʋ���һӳ��
����������ʱ��ɫһƬ�������ڵ����·����±ߵ��Ʋ�ԭ��������ɫ��
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"taohua",
  "west" : __DIR__"wulao",
]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
