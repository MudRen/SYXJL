#define MAX_ALT  2
#define MAX_DIS 7

#define MAX_DIR  8

mapping *quests;
mapping *read_table(string file);
string *roomlines;
varargs void init_dynamic_quest(int hard);
varargs int spread_quest(mapping one_quest, int hard);
object find_env(object ob);
varargs int already_spreaded(string str, int hard);
int quest_reward( object me, object who,object quest_item);
string dyn_quest_list();
string locate_obj(object me,string str);

void create()
{
        string file;
        quests = read_table("/task/dynamic_quest");
        file = read_file("/task/dynamic_location");
        roomlines = explode(file,"\n"); 
//      CRON_D->set_last_hard_dis();
        init_dynamic_quest(1);
}

int quest_reward(object me, object who,object quest_item)
{
        mapping quest;
        int exp,pot,score;
        quest = quest_item->query("dynamic_quest");
        if(base_name(who) != quest["owner_name"]) return 0;
        exp =200+random(500);
        pot = exp/7;
        score = random(10)+1;
        me->add("combat_exp",exp);
        me->add("potential",pot);
        me->add("score",score);
        tell_object(me,"�㱻�����ˣ�\n" +
        chinese_number(exp) + "��ʵս����\n"+
        chinese_number(pot) + "��Ǳ��\n" +
        chinese_number(score)+"���ۺ�����\n");
        me->add("TASK",1);
        if( !undefinedp(quest["fin_func"]))
        call_other(this_object(),quest["fin_func"],me,who,quest_item);
        if(quest_item)
        destruct(quest_item);
        return 1;
}

varargs void init_dynamic_quest(int hard)
{
        int i;

// On average tasks get renewed every 30 mins
        if ( (hard)?1:!random(30) )
                for( i=0; i < sizeof(quests); i++)
                        spread_quest(quests[i],hard);

        remove_call_out("init_dynamic_quest");
        call_out("init_dynamic_quest", 300);
}
varargs int spread_quest(mapping quest, int hard)
{
        object obj0;
        object cur_obj;
        object tar;
        object *inv;
        object *target=({});
        int i;
        string location;
        if(already_spreaded(quest["file_name"],hard)) return 0;
        reset_eval_cost();
        location = roomlines[random(sizeof(roomlines))];
        obj0=find_object(location);
        if(obj0) obj0->reset();
        else obj0=load_object(location);
        cur_obj =obj0;
        if(cur_obj) {
                inv = all_inventory(cur_obj);
                for(i=0; i<sizeof(inv); i++) {
                        if(inv[i]->is_character() && !userp(inv[i]))
                                target += ({ inv[i] });
                                if(inv[i]->is_container()) target += ({ inv[i] });
                }
        }
        if(sizeof(target)) cur_obj = target[random(sizeof(target))];
        if(cur_obj) {
                tar = new(quest["file_name"]);
                tar->set("value",0);
                tar->set("dynamic_quest",quest);
                tar->move(cur_obj);             
        }
        return 1;
}

string dyn_quest_list()
{
        string output="";
        object owner,item;
        int i;
        for( i=0; i < sizeof(quests); i++)
        {
        reset_eval_cost();
        if(!objectp(owner= find_object(quests[i]["owner_name"])))
        owner = load_object(quests[i]["owner_name"]);
        if(!objectp(item= find_object(quests[i]["file_name"])))
        item = load_object(quests[i]["file_name"]);
        if(already_spreaded(quests[i]["file_name"]))
        {
        if(random(2))
        output += sprintf("%s��%s��%s��\n",owner->query("name"),item->query("name"),item->query("id"));
        else
        output = sprintf("%s��%s��%s��\n",owner->query("name"),item->query("name"),item->query("id")) + output;
        }
        else
        {
        if(random(2))
        output += sprintf("%s��%s��%s��������ɡ�\n",owner->query("name"),item->query("name"),item->query("id"));
        else
        output = sprintf("%s��%s��%s��������ɡ�\n",owner->query("name"),item->query("name"),item->query("id")) + output;
        }
        }
        return output;
}

string locate_obj(object me,string strr)
{
        string *distance = ({
"����", "�ܽ�", "�ȽϽ�", "��Զ",
"����", "�Ƚ�Զ", "��Զ", "��Զ"
        });
        string *altitude =({
"�ߴ�", "�ط�", "�ʹ�"
        });
        string *directions=({
"��Χ","����", "�Ϸ�", "����","����",
"������","������","���Ϸ�","���Ϸ�"
        });
        object ob, tmpobj, *ob_list;
        object item;
        string output,dis,alt,dir;
        int i;
        int x,y,z,x0,y0,z0;
        int realdis;
        int tmp;
        string *dir1;
        string *dir2;
        string str="";
        reset_eval_cost();
        for( i=0; i < sizeof(quests); i++) {
                if(!objectp(item= find_object(quests[i]["file_name"])))
                        item = load_object(quests[i]["file_name"]);
                if(item->query("id") == strr || item->query("name") == strr) str = quests[i]["file_name"];
        }
        if(str != "") {
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        ob=find_env(ob_list[i]);
                        if(ob) {
                                dir1=explode(base_name(environment(me)),"/");
                                dir2=explode(base_name(ob),"/");
                                if(sizeof(dir1)==3 && sizeof(dir2)==3 && dir1[0]=="d" && dir2[0]=="d" && dir1[1]!=dir2[1]) {
                                        switch(dir2[1]) {
                                                case "baituo"   :       alt="����ɽ";
                                                break;
                                                case "city"     :       alt="���ݳ�";
                                                break;
                                                case "city2"    :       alt="������";
                                                break;
                                                case "dali"     :       alt="����";
                                                break;
                                                case "emei"     :       alt="����ɽ";
                                                break;
                                                case "heimuya"  :       alt="��ľ��";
                                                break;
                                                case "gumu"     :       alt="��Ĺ";
                                                break;
                                                case "honghua"  :       alt="�컨��";
                                                break;
                                                case "huanggon" :       alt="������";
                                                break;
                                                case "huanhua"  :       alt="佻�Ϫ";
                                                break;
                                                case "huashan"  :       alt="��ɽ";
                                                break;
                                                case "kunlun"   :       alt="����ɽ";
                                                break;
                                                case "lingjiu"  :       alt="���չ�";
                                                break;
                                                case "mj"       :       alt="����";
                                                break;
                                                case "mr"       :       alt="����Ľ��";
                                                break;
                                                case "quanzhen" :       alt="ȫ���";
                                                break;
                                                case "quanzhou" :       alt="Ȫ�ݳ�";
                                                break;
                                                case "shaolin"  :       alt="����ɽ";
                                                break;
                                                case "shashou"  :       alt="ɱ��¥";
                                                break;
                                                case "taishan"  :       alt="��ɽ";
                                                break;
                                                case "taohua"   :       alt="�һ���";
                                                break;
                                                case "tls"      :       alt="������";
                                                break;
                                                case "wenrou-po":       alt="���ݳ�";
                                                break;
                                                case "wudang"   :       alt="�䵱ɽ";
                                                break;
                                                case "wugongzhen":      alt="�����";
                                                break;
                                                case "xiaoyao"  :       alt="��ң��";
                                                break;
                                                case "xingxiu"  :       alt="���޺�";
                                                break;
                                                case "xuedao"   :       alt="Ѫ����";
                                                break;
                                                case "xueshan"  :       alt="ѩɽ";
                                                break;
                                                default         :       alt="ĳ��";
                                                break;
                                        }
                                        output = "��"+ob_list[i]->query("name")+"���ƺ���"+alt+"��Χ��\n";
                                }
                                else {
                                        x0= (int)environment(me)->query("coor/x");
                                        y0= (int)environment(me)->query("coor/y");
                                        z0= (int)environment(me)->query("coor/z");
                                        x=(int)ob->query("coor/x")-x0;
                                        y=(int)ob->query("coor/y")-y0;
                                        z=(int)ob->query("coor/z")-z0;
                                        realdis=0;
                                        if(x<0)realdis-=x; else realdis+=x;
                                        if(y<0)realdis-=y; else realdis+=y;
                                        if(z<0)realdis-=z; else realdis+=z;
                                        tmp =(int)  realdis/50;
                                        if(tmp>MAX_DIS) tmp = MAX_DIS;
                                        dis=distance[tmp];
                                        if(z>0) alt=altitude[0];
                                        if(z<0) alt=altitude[2];
                                        if(z==0) alt=altitude[1];
                                        if(x==0&&y==0) dir=directions[0];
                                        if(x==0&&y>0) dir=directions[1];
                                        if(x==0&&y<0) dir=directions[2];
                                        if(x>0&&y==0) dir=directions[3];
                                        if(x<0&&y==0) dir=directions[4];
                                        if(x>0&&y>0) dir=directions[5];
                                        if(x<0&&y>0) dir=directions[6];
                                        if(x>0&&y<0) dir=directions[7];
                                        if(x<0&&y<0) dir=directions[8];
                                        output = "��"+ob_list[i]->query("name")+"���ƺ���"+dir+dis+"��"+alt+"��\n";
                                }
                                return output;
                        }
                }
        }
        else if(wizardp(me)) {
                tmpobj = find_player(strr);
                if(!tmpobj) tmpobj = find_living(strr);
                if(!tmpobj) return "";
                ob = find_env(tmpobj);
                if(ob) {
                        x0= (int)environment(me)->query("coor/x");
                        y0= (int)environment(me)->query("coor/y");
                        z0= (int)environment(me)->query("coor/z");
                        x=(int)ob->query("coor/x")-x0;
                        y=(int)ob->query("coor/y")-y0;
                        z=(int)ob->query("coor/z")-z0;
                        realdis=0;
                        if(x<0)realdis-=x; else realdis+=x;
                        if(y<0)realdis-=y; else realdis+=y;
                        if(z<0)realdis-=z; else realdis+=z;
                        tmp =(int)  realdis/50;
                        if(tmp>MAX_DIS) tmp = MAX_DIS;
                        dis=distance[tmp];
                        if(z>0) alt=altitude[0];
                        if(z<0) alt=altitude[2];
                        if(z==0) alt=altitude[1];
                        if(x==0&&y==0) dir=directions[0];
                        if(x==0&&y>0) dir=directions[1];
                        if(x==0&&y<0) dir=directions[2];
                        if(x>0&&y==0) dir=directions[3];
                        if(x<0&&y==0) dir=directions[4];
                        if(x>0&&y>0) dir=directions[5];
                        if(x<0&&y>0) dir=directions[6];
                        if(x>0&&y<0) dir=directions[7];
                        if(x<0&&y<0) dir=directions[8];
                        output = "��"+tmpobj->query("name")+"���ƺ���"+dir+dis+"��"+alt+"��\n";
                        return output;
                }
        }
        return "";
}

varargs int already_spreaded(string str,int hard)
{
        object ob,*ob_list;
        int i;
        if(!str) return 0;
        if(hard)
        {
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                { ob_list[i]->move(VOID_OB);
                 destruct(ob_list[i]);
                }
        }
        return 0;
        }
        else
        {
        if(!str) return 0;
        ob_list = children(str);
        for(i=0; i<sizeof(ob_list); i++) {
                ob=find_env(ob_list[i]);
                if(ob)
                        return 1;
        }
        return 0;
        }
}

object find_env(object ob)
{
        while(ob)
        {
        if(ob->query("coor") ) return ob;
        else ob=environment(ob);
        }
        return ob;
}

mapping *read_table(string file)
{
        string *line, *field, *format;
        mapping *data;
        int i, rn, fn;

        line = explode(read_file(file), "\n");
        data = ({});
        for(i=0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !pointerp(field) ) {
                        field = explode( line[i], ":" );
                        continue;
                }
                if( !pointerp(format) ) {
                        format = explode( line[i], ":" );
                        continue;
                }
                break;
        }

        for( rn = 0, fn = 0; i<sizeof(line); i++) {
                if( line[i]=="" || line[i][0]=='#' ) continue;
                if( !fn ) data += ({ allocate_mapping(sizeof(field)) });
                sscanf( line[i], format[fn], data[rn][field[fn]] );
                fn = (++fn) % sizeof(field);
                if( !fn ) ++rn;
        }
        return data;
}

void big_reward(object me, object who, object item)
{
        tell_object(me,"�����У���\n");
}

void execute_accept_object(object me, object who, object item)
{
        who->accept_object(me,item);
}
