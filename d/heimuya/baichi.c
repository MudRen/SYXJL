inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
��������ڣ������Ϻ�������������������ʯ�ף�ɽ��ʮ�ֶ��͡�
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "westup" : __DIR__"shijie",
  "eastup" : __DIR__"suodao",
  "south" : __DIR__"meimao",
  "eastdown" : __DIR__"shandao2"
]));
        set("no_clean_up", 0);
        set("outdoors", "riyue" );

        setup();
        replace_program(ROOM);
}
