inherit ROOM;

void create()
{
        set("short", "�ص�");
        set("long", @LONG
�ص�һ·���£����Ե��ż�յ�͵ƣ�����綹��һƬ�������أ����ҵ�
��������������ת����ͷ���ۻ���
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"xiaohuayuan",
"up" : __DIR__"dadian",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
