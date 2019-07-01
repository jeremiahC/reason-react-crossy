module App = {
    [@react.component]
    let make = () => {
        <div className="container">
            <Land.Draw />
        </div>
    };
};

ReactDOMRe.renderToElementWithId(<App />, "index1");