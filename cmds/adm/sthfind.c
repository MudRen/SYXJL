inherit TASK_D;
string locate_obj1(object me,string str);

int main(object me, string str)
{
        string output = "";
        if(!str) return notify_fail("ָ���ʽ: sthfind <��Ʒ>\n");
        output = locate_obj1(me,str);
        if(output=="")
                return notify_fail("ȷ������"+str+"�Ĵ��λ�á�\n");
        write(output);
        return 1;
}

string locate_obj1(object me,string strr)
{
        object ob, *ob_list;
        object item,room,room2;
        string output;
        string str="";
        int i;

        reset_eval_cost();

        for(i=0; i < sizeof(quests); i++) {
                if(!objectp(item= find_object(quests[i]["file_name"])))
                        item = load_object(quests[i]["file_name"]);
                if(item->query("id") == strr || item->query("name") == strr)
                        str = quests[i]["file_name"];
        }
        if(str != "") {
                room = environment(me);
                ob_list = children(str);
                for(i=0; i<sizeof(ob_list); i++) {
                        ob=find_env(ob_list[i]);
                        if(ob) {
                                room2 = ob;
                                output = "��"+ob_list[i]->query("name")+"���ƺ���"+room2->query("short")+(string)file_name(room2)+"��\n";
                                return output;
                        }
                }
        }

        return "";
}

