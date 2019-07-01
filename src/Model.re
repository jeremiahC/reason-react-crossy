module Player = {
    type t = {
        position: array(int)
    }
}

module Board = {
    type re = {
        ground: array(array(int))
    }
}

module Car = {
    type t = {
        position: list(array(int))
    }
}

module State = {
    type t =  {
        playerPosition: (int, int),
        ground: array(array(int))
    }

    let initial_state = {
        playerPosition: (0, 0),
        ground: Array.make_matrix(15, 9, 0)
    }
    

    let reducer = (state, action) => {
        let (y, x) = state.playerPosition;
        Js.log((y, x));
        let new_state = switch (action) {
        | "up" => {
            state.ground[y][x] = 0;
            {
                ...state,
                playerPosition: (y - 1, x) 
            }};
        | "down" => {
            state.ground[y][x] = 0;
            {
                ...state,
                playerPosition: (y + 1 , x) 
            }};
        | "left" => {
            state.ground[y][x] = 0;
            {
                ...state,
                playerPosition: (y, x - 1) 
            }};
        | "right" => {
            state.ground[y][x] = 0;
            {
                ...state,
                playerPosition: (y, x + 1) 
            }};
        };

        new_state;
    }
}