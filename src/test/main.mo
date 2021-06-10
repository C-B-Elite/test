import Int "mo:base/Int";
import Time "mo:base/Time";
import Array "mo:base/Array";
import Random "mo:base/Random";
import Nat8 "mo:base/Nat8";
import List "mo:base/List";
import Nat32 "mo:base/Nat32";
import Text "mo:base/Text";

actor {
    //private var array : Array.Array<Nat8> = [0];
    private var list = List.nil<Nat32>(); 
    var b : Blob = Text.encodeUtf8("");
    private var random : Random.Finite = Random.Finite(b);
    private func createNumber() : Text{
        var i : Nat32 = 10_000_000;
        let before = Time.now();
        while (i != Nat32.fromNat(0)) {
            list := List.append(list, ?(i, null));
            i-=1;
        };
        let end = Time.now();
        let elapsedSeconds = (end - before) / 1000_000_000;
        Int.toText(elapsedSeconds)
    };

    public query func findNumber() : async Text{
        //average time
        var create_time = createNumber();
        
        //time
        var i = 100;
        let before = Time.now();
        while (i != 0){
            var randomNumber = switch(random.range(Nat8.fromNat(23))){
                case (?num) { num };
                case _ { 0 };
            };
            var r_num = Nat32.fromNat(randomNumber);
            switch(List.find<Nat32>(list, func (n :Nat32) : Bool{
                if (n == r_num) { true }
                else{ false }
            })){
                case (?num) { () };
                case _ { () };
            };
            i -= 1;
        };
        let after = Time.now();
        let elapsedSeconds = (after - before) / 1000_000_000;
        "find time : " # Int.toText(elapsedSeconds)
    }; 



    
    public func main(name : Text) : async Text {
        //caculate time
        var createTime = createNumber();
        //var findTime = findNumber();
        return "create time :" # createTime;
    };
};
