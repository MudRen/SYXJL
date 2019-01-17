// room: /kunlun/zhongt.c 



#include <ansi.h>

inherit ROOM;

int do_dao(string arg);



void create()

{

        set("short", "中厅");

        set("long", @LONG
这里是中厅，陈设较为正规气派。正中有一张紫檀木的八仙桌，上面
有一盆花苗(huamiao),几个童仆侍立在旁边，由于铁琴先生不轻易见客，
所以一般由昆仑派的大弟子出面， 在这里和客人或者身份平常的武林人物
攀谈，左右都是走廊。
LONG

        );



        set("exits", ([

                "south" : __DIR__"qianting",

                "north" : __DIR__"dating",

                "west" : __DIR__"zoul_3",

                "east" : __DIR__"zoul_4",

        ]));

       set("objects",([

                "/d/kunlun/npc/jiangtao" : 1,
        ]));



        set("item_desc", ([

               "huamiao" : "这是株从深山移植的仙果花苗，因为长于凡间而失去灵气。枝叶萎靡，不能开花结果!\n"

        ]) );



        set("dao_count", 3);

        set("hua_count", 2);



        setup();

//      replace_program(ROOM);

}



void init()

{

        add_action("do_dao", "dao");

        add_action("do_ci", "ci");



}

int do_dao(string arg)

{       mapping fam;

        object me;

        object obhua;

        me = this_player();





        if ( !arg || arg != "huamiao" )

                return 0;



        if (!(fam = me->query("family")) || fam["family_name"] != "昆仑派")

               return notify_fail("你与本派素无来往，又何必无事献殷勤!\n");



    if (! present("xiang cha", this_player()))

        return notify_fail("你拿什么来浇花?!\n");

     

     message_vision(HIG"$N细心地把茶杯里的女儿香到在花苗上。\n"NOR, me);

     if (present("xiang cha", me))

     destruct(present("xiang cha",me));



     add("dao_count", -1);

     if (query("dao_count") > 0) {

        message_vision(HIG"香茶被花苗吸收，枝叶长得更翠绿了。\n"NOR, me);

        return 1;

        }

     if (query("hua_count") >=1)

      {

        add("hua_count", -1);

        write(HIM"突然花苗中间长出一个花蕾，随即开花，原来这就是昆仑山特有的曼陀箩花!\n"NOR);

        message_vision("$N小心翼翼地摘下曼陀箩花，满脸高兴地揣入怀中。\n",me);

        obhua = new("/d/kunlun/obj/hua");

        obhua->move(me);

        set("dao_count", 3);

        return 1;

      }

      else

      {

       set("dao_count", 3);

       message_vision(HIG"由于营养不良，花苗不能开花。。。。\n"NOR, me);

      }

        return 1;

}



