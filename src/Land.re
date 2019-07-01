open Model.State;

module Draw = { 
    [@react.component]
    let make = () => {
        let (state, dispatch) = React.useReducer(reducer, initial_state);

        let cells = (rowGround) => {
            Array.map((ground) => {
                <div className="col-1 text-center cell">
                    {React.string(string_of_int(ground))}
                </div>
            },rowGround);
        }
    
        let renderRow = () => {
            let rowGrounds = state.ground;
            let (x, p) = state.playerPosition;

            //set player position
            rowGrounds[x][p] = 1;
    
            Array.map((rowGround) => {
                <div className="col-12 row center p-0">
                    {React.array(cells(rowGround))}
                </div>
            }, rowGrounds);
        };

        let handleClick = (e) => {
            ReactEventRe.Mouse.preventDefault(e);
            let element = e->ReactEvent.Mouse.target;
            let keyValue = element##value;
            
            switch (keyValue) {
            | "up" => dispatch("up");
            | "down" => dispatch("down");
            | "left" => dispatch("left");
            | "right" => dispatch("right");
            }
            /* Js.log(e.); */
        };

        <div className="row my-5">
            {ReasonReact.array(renderRow())}
            <div>
                <button onClick={handleClick} value="up">
                    {React.string("up")}
                </button>

                <button onClick={handleClick} value="down">
                    {React.string("down")}
                </button>

                <button onClick={handleClick} value="left">
                    {React.string("left")}
                </button>

                <button onClick={handleClick} value="right">
                    {React.string("right")}
                </button>
            </div>
        </div>
    }
}