inherit ROOM;

void create()
{
        set("short", "山道");
        set("long", @LONG
这一路上山，地势极险，脚下是万丈深谷，而山道极之
陡峭窄小，倘若一不留神，必将命丧于此。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
  "westup" : __DIR__"baichi",
  "eastdown" : __DIR__"shandao",
]));
          setup();
}
