//room1.c
inherit ROOM;
void create()
{
  set("short","练功室");
  set("long",
      "这里是白驼山弟子的练功室。有练功铜人陪你练功。\n"
    );
  set("exits",([
      "out" : __DIR__"liangong",
     ]));

 set("objects",([
        "/d/heimuya/npc/tong-ren":2,
     ]));
 set_temp("full",0);
 setup();

}

void init()
{ object ob=this_player();
  if((int)query_temp("full")==3)
   {
    message_vision("$N一见房间里已经有人了，只好退了出去。\n",ob);
    ob->move(__DIR__"liangong");
    return;
   }
  add_temp("full" ,1);
  return;
}

int valid_leave(object who, string dir)
{
 add_temp("full",-1);
 return 1;
}
