inherit ROOM;

void create ()
{
  set ("short", "幽冥殿");
  set ("long", @LONG

这里便是名闻天下，令人提起心惊胆寒的阎幽冥殿。人死后都会
在这里受到应有的处置。正前一张大桌。正前坐着冥王哈笛斯，
统管整个地府的秩序。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"youmingjie",
]));
  set("hell", 1);
  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/yanluowang" : 1,
]));
  setup();

}
