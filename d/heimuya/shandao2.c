inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��һ·��ɽ�����Ƽ��գ�������������ȣ���ɽ����֮
����խС������һ�����񣬱ؽ���ɥ�ڴˡ�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"baichi",
  "eastdown" : __DIR__"shandao",
]));
          setup();
}
